//
// Created by Robert JONES on 2016/12/06.
//

#ifndef INC_42RUN_MODEL_H
#define INC_42RUN_MODEL_H

#include "support.h"
#include "structs.h"
#include "shader.h"
#include "mesh.h"

class Model {
public:
    Model(GLchar *path) { this->loadModel(path); };

    void Draw(Shader shader);

private:
    vector<Mesh> meshes;
    string directory;
    vector<t_texture> textures_loaded;

    void loadModel(string path);

    void processNode(aiNode *node, const aiScene *scene);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    vector<t_texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                         string typeName);
};

#endif //INC_42RUN_MODEL_H
