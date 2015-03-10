
local testname, testkind = ...

project(testname)
    kind(testkind)
    debugdir "../.."
    debugcommand "%{cfg.buildtarget.directory}../../../bin/%{cfg.buildtarget.name}"
    includedirs { "../PGTA", "../AudioMixer/include", "../tests/Common" }
    links
    {
        "PGTALib",
        "AudioMixer"
    }
    defines
    {
        "SDL_MAIN_HANDLED",
        "_REENTRANT"
    }
    files
    {
       "../tests/"..testname.."/**.h",
       "../tests/"..testname.."/**.cpp",
       "../tests/Common/**.h",
       "../tests/Common/**.cpp"
    }

    filter "platforms:x32"
        targetsuffix "_x32"
    filter "platforms:x64"
        targetsuffix "_x64"
    filter {}

    postbuildcommands
    {
        "{MKDIR} ../../../bin",
        "{COPY} %{cfg.buildtarget.name} ../../../bin/"
    }

    run_include("sdl2_include.lua", "SDL2")

project "*"
