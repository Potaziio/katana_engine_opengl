#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"

class Camera {
    private:
        glm::mat4 viewMatrix, projectionMatrix, transformMatrix;
    
        glm::vec3 cameraDirection;

        glm::vec3 cameraUp;
        glm::vec3 cameraRight;
        glm::vec3 cameraFront;

        float nearPlanes, farPlanes, camFov;
    public:
        glm::vec3 cameraPos;
        Camera(glm::vec3 cameraPos, float nearPlanes, float farPlanes, float camFov);
        Camera();


        void updateViewMatrix();
        glm::mat4 getViewMatrix();
        glm::mat4 getProjectionMatrix();
        glm::mat4 getTransfomMatrix();
};
