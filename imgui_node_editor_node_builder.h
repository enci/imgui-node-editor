#pragma once

#include <imgui_node_editor.h>

namespace ax { namespace NodeEditor {

// Simplified node builder using standard ImGui layout (BeginGroup/EndGroup).
// Draws Blender-style colored header rectangles on nodes.
struct NodeBuilder
{
    void Begin(NodeId id);
    void End();

    void Header(const ImVec4& color = ImVec4(1, 1, 1, 1));
    void EndHeader();

    // Column layout helpers for input/output pin groups
    void BeginColumns();
    void NextColumn();
    void EndColumns();

private:
    NodeId  CurrentNodeId = 0;
    ImU32   HeaderColor = IM_COL32(255, 255, 255, 255);
    ImVec2  HeaderMin;
    ImVec2  HeaderMax;
    bool    HasHeader = false;
};

}} // namespace ax::NodeEditor
