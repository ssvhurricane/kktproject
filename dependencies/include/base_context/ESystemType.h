#pragma once

enum ESystemType 
{
    //-------- Engine --------//
    // CoreLayer.
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
 
    AISystem,
    AnimationSystem,
    AudioSystem

    //-------- Editor --------//
};

