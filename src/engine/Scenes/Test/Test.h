#include <API_ALL.h>
#include "ChunkRenderer.h"
#include "ChunkManager.h"
#include <list>
#include <unordered_set>
#include <queue>
#include "ChunkLoader.h"

class Test:public Scene {
    ChunkManager manager;
    Shader chunk_shader=Shader("../src/engine/Scenes/Test/Shader/VoxelVertex.glsl","../src/engine/Scenes/Test/Shader/VoxelFragment.glsl");
    EntityMaterial chunk_transparent_material=EntityMaterial(chunk_shader,Color::WHITE);
    EntityMaterial chunk_solid_material=EntityMaterial(chunk_shader,Color::WHITE);
    ChunkLoader loader=ChunkLoader(*this,manager,chunk_solid_material,chunk_transparent_material);
    FPSController* cam;
public:

    void init(Canvas &canvas, Renderer &renderer, Input &input) override;

    virtual ~Test();

    void update(float delta) override;

    void render() const override;

    void draw() const override;
};

