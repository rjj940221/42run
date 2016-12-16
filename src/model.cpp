//
// Created by Robert JONES on 2016/12/06.
//

//#include "../includes/mesh.h"
#include "../includes/model.h"


void Model::Draw(Shader shader){
    for (int i = 0; i < this->meshes.size(); i++)
        this->meshes[i].Draw(shader);
}

void Model::loadModel(string path) {
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        cout << "Error::ASSIMP::" << import.GetErrorString()<<endl;
        return;
    }
    this->directory = path.substr(0, path.find_last_of('/'));
    this->processNode(scene->mRootNode, scene);
}

vector<t_texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName)
{
    vector<t_texture> textures;
    for(GLuint i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        // Check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
        GLboolean skip = false;
        for(GLuint j = 0; j < this->textures_loaded.size(); j++)
        {
            if(this->textures_loaded[j].path == str)
            {
                textures.push_back(this->textures_loaded[j]);
                skip = true; // A texture with the same filepath has already been loaded, continue to next one. (optimization)
                break;
            }
        }
        if(!skip)
        {   // If texture hasn't been loaded already, load it
            t_texture texture;
            texture.id = TextureFromFile(str.C_Str(), this->directory);
            texture.type = typeName;
            texture.path = str;
            textures.push_back(texture);
            this->textures_loaded.push_back(texture);  // Store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
        }
    }
    return textures;
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    for(GLuint i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

        this->meshes.push_back((this->processMesh(mesh, scene)));
    }
    for(GLuint i = 0; i < node->mNumChildren; i++)
    {
        this->processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
        vector<t_vertex> vertices;
        vector<GLuint> indices;
        vector<t_texture> textures;

        for (GLuint i = 0; i < mesh->mNumVertices; i++) {
            t_vertex vertex;
            glm::vec3 vector;
            vector.x = mesh->mVertices[i].x;
            vector.y = mesh->mVertices[i].y;
            vector.z = mesh->mVertices[i].z;
            vertex.Position = vector;
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.Normal = vector;
            if (mesh->mTextureCoords[0]) {
                glm::vec2 vec;
                vec.x = mesh->mTextureCoords[0][i].x;
                vec.y = mesh->mTextureCoords[0][i].y;
                vertex.TexCoords = vec;
            } else
                vertex.TexCoords = glm::vec2(0.0f, 0.0f);
            vertices.push_back(vertex);
        }
        for (GLuint i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (GLuint j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }
        if (mesh->mMaterialIndex >= 0) {
            aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
            vector<t_texture> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE,
                                                                     "texture_diffuse");
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
            vector<t_texture> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR,
                                                                      "texture_specular");
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
        }
        return Mesh(vertices, indices, textures);
}