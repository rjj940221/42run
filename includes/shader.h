//
// Created by Robert JONES on 2016/12/06.
//

#ifndef INC_42RUN_SHADER_H
#define INC_42RUN_SHADER_H

#include "structs.h"

class Shader {
public:
    Shader(const char *vertex_file_path, const char *fragment_file_path);

    void useShader() { glUseProgram(this->Program); };

    GLuint getProgram() { return (this->Program); };
private:
    GLuint Program;
};

#endif //INC_42RUN_SHADER_H
