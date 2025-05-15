# pragma once
# include "setup.h"
# include <memory>

struct Platform;
struct ImDrawData;
struct ImVec4;
using ImTextureID = unsigned long long;

struct Renderer
{
    virtual ~Renderer() {};

    virtual bool Create(Platform& platform) = 0;
    virtual void Destroy() = 0;

    virtual void NewFrame() = 0;

    virtual void RenderDrawData(ImDrawData* drawData) = 0;

    virtual void Clear(const ImVec4& color) = 0;
    virtual void Present() = 0;

    virtual void Resize(int width, int height) = 0;
};

std::unique_ptr<Renderer> CreateRenderer();
