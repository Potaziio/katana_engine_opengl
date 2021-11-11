#include "../include/Shader.hpp"

Shader::Shader(std::string ShaderPath) {
    std::ifstream myShaderFile;
    std::string line;

    std::string source;

    myShaderFile.open(ShaderPath);

    if (!myShaderFile.is_open()) {std::cout << "ERROR: " << "failed while opening shader file, wrong path???" << std::endl; exit(EXIT_FAILURE);}

    while (getline(myShaderFile, line)) {
        source += line;
        source += "\n";
    }

    std::regex type_regex("(#type)( )+([a-zA-Z]+)");
    std::smatch res;

    std::sregex_token_iterator iter(source.begin(),
        source.end(),
        type_regex,
        -1);
    std::sregex_token_iterator end;

    for ( ; iter != end; ++iter) {
        holder.push_back(*iter);
    }

    vertexShaderSource = holder[1].c_str();
    fragmentShaderSource = holder[2].c_str();

    myShaderFile.close();
}

void Shader::compileShaders() {

    // ===============================
    // VERTEX SHADER
    // ===============================

    // Create both vertex and fragment shader variables
    unsigned int vertexShader, fragmentShader;

    // Create vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Send shader source to vertex shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Compile shader
    glCompileShader(vertexShader);

    // Check for errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(EXIT_FAILURE);
    }

    // ===============================
    // FRAGMENT SHADER
    // ===============================
   
    // Create shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Send source to shader 
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // Compile shader
    glCompileShader(fragmentShader);

    // Check for errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(EXIT_FAILURE);
    }

    // Link shaders to a shader program to use for rendering;

    shaderProgram = glCreateProgram();

    // Link attributes
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for errors 

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        exit(EXIT_FAILURE);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::sendFloat(const char* name, float val) {
    use();
    glUniform1f(glGetUniformLocation(shaderProgram, name), val);
}

void Shader::sendInt(const char* name, int val) {
    use();
    glUniform1i(glGetUniformLocation(shaderProgram, name), val);
}

void Shader::sendTexture(const char* name, Texture texture, GLint position) {
    use();
    glUniform1i(glGetUniformLocation(shaderProgram, name), position);
}

void Shader::sendMat4(const char* name, glm::mat4 mat) {
    use();
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::use() {
    if (!beingUsed) 
        glUseProgram(shaderProgram);
}

void Shader::detach() {
    glUseProgram(0); 
    beingUsed = false;
}

unsigned int Shader::getProgram() {
    return shaderProgram;
}
