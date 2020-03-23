#include <API_ALL.h>
#include "ChunkRenderer.h"
#include "ChunkManager.h"
#include <list>
#include <unordered_set>
#include <queue>
#include "ChunkLoader.h"
#include "CameraFrustum.h"
class Test:public Scene {
    ChunkManager manager;
    CameraFrustum camera_frustum=CameraFrustum(*this);
    ChunkLoader loader=ChunkLoader(*this,manager,camera_frustum);

public:

    void init(Canvas &canvas, Renderer &renderer, Input &input) override;

    virtual ~Test();

    void update(float delta) override;

    void render() const override;

    void draw() const override;
};

