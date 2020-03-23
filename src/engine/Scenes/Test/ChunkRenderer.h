#include <Ressources/VAO.h>
#include "Entities/MeshRenderer.h"
#include "Chunk.h"
class Voxel;

class ChunkManager;

#include <future>
class CameraFrustum;
class ChunkRenderer : public Entity {
    enum Side{
        up,
        down,
        left,
        right,
        front,
        back
    };
    Camera** pCamera;
    unsigned char *data;
    Mesh solid_voxels;
    Mesh transparent_voxels;
    Chunk *current_chunk;
    ChunkManager *chunkManager;
    std::vector<unsigned int> indicies;
    std::vector<vec3> vertex_positions;
    std::vector<Color> vertex_colors;
    const EntityMaterial* transparent_material;
    const EntityMaterial* solid_material;
    Chunk* chunk_up;
    Chunk* chunk_down;
    Chunk* chunk_left;
    Chunk* chunk_right;
    Chunk* chunk_front;
    Chunk* chunk_back;
    std::queue<std::future<void>> thread_results;
    std::mutex mesh_mutex;
    CameraFrustum* camera_frustum;
public:
    ChunkRenderer(const EntityMaterial &solid_material,const EntityMaterial &transparent_material, ChunkManager &chunkManager,CameraFrustum& cameraFrustum);

    void setChunk(Chunk *chunk);

    Chunk &getChunk() const;

    void rebuild();
    void onBuildFinish();

    void init(Scene &scene) override;
    vec3 getChunkCenter() const;
    void update(float delta, Scene &scene) override;

    void draw(const Scene &scene) const override;
    float getDistanceToCamera() const;
    void createVoxel(int x, int y, int z, const Voxel &voxel);
    void createSide(int x,int y,int z,const Voxel& voxel, Side side);
    std::size_t operator<(const ChunkRenderer &other) const;
};
