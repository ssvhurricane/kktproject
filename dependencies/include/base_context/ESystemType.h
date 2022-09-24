#pragma once

enum ESystemType 
{
    //-------- Engine --------//
    // CoreLayer.
    AnalyticSystem,
    ApprovalSystem,
    ConfigSystem,
    CRSystem,
    FileSystem,
    LocalizationSystem,
    LogSystem, 
    MathSystem,
    MemorySystem,
    ParserSystem,
    RandomNumGenSystem,
    RTTISystem,
    StringSystem,
    VideoSystem,

    // Input Layer.
    InputSystem,

    // Network Layer.
    NetworkSystem,

    // Physic Layer.
    PhysicSystem,

    // ProfilingLayer.
    ProfilingSystem,


    // Rendering Layer.
    RenderSystem,
    
    // Resource Layer.
    ResourceSystem,

    // Test Layer.
    TestSystem,

    // World Layer.
    WorldSystem,
    SceneSystem,
    ObjectSystem,

    //-------- UI --------//
    // UI Layer.
    UISystem,

    // User sub system.
    ProjectSubSystem,
    SceneSubSystem,

    AISystem,
    AnimationSystem,
    AudioSystem

    //-------- Editor --------//
};

