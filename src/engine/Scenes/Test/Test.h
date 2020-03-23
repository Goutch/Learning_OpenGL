#include <API_ALL.h>
#include "ChunkRenderer.h"
#include "ChunkManager.h"
#include <list>
#include <unordered_set>
#include <queue>
#include "ChunkLoader.h"

class Test:public Scene {
    ChunkManager manager;

    ChunkLoader loader=ChunkLoader(*this,manager);

public:

    void init(Canvas &canvas, Renderer &renderer, Input &input) override;

    virtual ~Test();

    void update(float delta) override;

    void render() const override;

    void draw() const override;
};

