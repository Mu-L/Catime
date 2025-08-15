-- Project information
set_project("Catime")
set_version("1.0.0")

-- Set minimum xmake version requirement
set_xmakever("2.5.0")

-- Set default compilation mode
set_defaultmode("release")

-- Allow platform API usage
add_rules("mode.debug", "mode.release")

-- Force platform to Windows
set_plat("mingw")

-- Set default architecture
set_arch("x86_64")

-- Set MinGW toolchain
set_toolchains("mingw")

-- Global flag to prevent duplicate logo display
local logo_displayed = false

-- Define target
target("catime")
    -- Set as executable program
    set_kind("binary")
    
    -- Display logo before build (only once)
    before_build(function (target)
        if not logo_displayed then
            logo_displayed = true
            
            -- Clear screen and display elegant purple-themed ASCII art
            print("\x1b[2J\x1b[H")  -- Clear screen and move cursor to top
            print("")
            
            -- Elegant purple gradient ASCII art matching the cat logo
            print("\x1b[1m\x1b[38;2;138;43;226m" .. "██████╗ " .. "\x1b[38;2;147;112;219m" .. " █████╗ " .. "\x1b[38;2;153;102;255m" .. "████████╗" .. "\x1b[38;2;160;120;255m" .. "██╗" .. "\x1b[38;2;186;85;211m" .. "███╗   ███╗" .. "\x1b[38;2;221;160;221m" .. "███████╗" .. "\x1b[0m")
            print("\x1b[1m\x1b[38;2;138;43;226m" .. "██╔════╝" .. "\x1b[38;2;147;112;219m" .. " ██╔══██╗" .. "\x1b[38;2;153;102;255m" .. "╚══██╔══╝" .. "\x1b[38;2;160;120;255m" .. "██║" .. "\x1b[38;2;186;85;211m" .. "████╗ ████║" .. "\x1b[38;2;221;160;221m" .. "██╔════╝" .. "\x1b[0m")
            print("\x1b[1m\x1b[38;2;138;43;226m" .. "██║     " .. "\x1b[38;2;147;112;219m" .. " ███████║" .. "\x1b[38;2;153;102;255m" .. "   ██║   " .. "\x1b[38;2;160;120;255m" .. "██║" .. "\x1b[38;2;186;85;211m" .. "██╔████╔██║" .. "\x1b[38;2;221;160;221m" .. "█████╗  " .. "\x1b[0m")
            print("\x1b[1m\x1b[38;2;138;43;226m" .. "██║     " .. "\x1b[38;2;147;112;219m" .. " ██╔══██║" .. "\x1b[38;2;153;102;255m" .. "   ██║   " .. "\x1b[38;2;160;120;255m" .. "██║" .. "\x1b[38;2;186;85;211m" .. "██║╚██╔╝██║" .. "\x1b[38;2;221;160;221m" .. "██╔══╝  " .. "\x1b[0m")
            print("\x1b[1m\x1b[38;2;138;43;226m" .. "╚██████╗" .. "\x1b[38;2;147;112;219m" .. " ██║  ██║" .. "\x1b[38;2;153;102;255m" .. "   ██║   " .. "\x1b[38;2;160;120;255m" .. "██║" .. "\x1b[38;2;186;85;211m" .. "██║ ╚═╝ ██║" .. "\x1b[38;2;221;160;221m" .. "███████╗" .. "\x1b[0m")
            print("\x1b[1m\x1b[38;2;138;43;226m" .. " ╚═════╝" .. "\x1b[38;2;147;112;219m" .. " ╚═╝  ╚═╝" .. "\x1b[38;2;153;102;255m" .. "   ╚═╝   " .. "\x1b[38;2;160;120;255m" .. "╚═╝" .. "\x1b[38;2;186;85;211m" .. "╚═╝     ╚═╝" .. "\x1b[38;2;221;160;221m" .. "╚══════╝" .. "\x1b[0m")
            
            print("")
        end
    end)
    
    -- Add Windows specific settings
    add_defines("_WINDOWS")
    add_ldflags("-mwindows", {force = true})
    add_links("ole32", "shell32", "comdlg32", "uuid", "wininet", "winmm", "comctl32", "dwmapi", "user32", "gdi32", "shlwapi", "advapi32")
    
    -- Add resource files
    add_files("resource/resource.rc")
    add_files("resource/languages.rc")
    add_files("resource/catime.rc")
    
    -- Add source files
    add_files("src/*.c")
    
    -- Add header search paths
    add_includedirs("include", "libs/miniaudio")
    
    -- Disable certain warning options
    add_cxflags("-Wno-unknown-warning-option", {force = false})  -- Disable warnings about unknown warnings
    
    -- Add compilation options
    if is_mode("release") then
        -- Basic optimization options
        add_cflags("-O3", "-mtune=generic", "-ffunction-sections", "-fdata-sections", "-fno-strict-aliasing")
        
        -- Add LTO (Link Time Optimization) support
        add_cflags("-flto")
        add_ldflags("-flto")
        
        -- More optimization flags
        add_cflags("-fno-exceptions", "-fomit-frame-pointer", "-fmerge-all-constants")
        add_cflags("-fno-math-errno", "-fno-trapping-math", "-ffast-math")
        
        -- Remove unnecessary parts
        add_ldflags("-Wl,--gc-sections", "-s", "-Wl,--strip-all")
        
        -- Use smaller runtime library
        add_cflags("-Os", {force = true})  -- Prefer size optimization over speed
        
        add_defines("NDEBUG")
    end
    
    -- Set output directory
    set_targetdir("$(builddir)")
    set_objectdir("build")
    
    -- Add miniaudio implementation definition
    add_defines("MINIAUDIO_IMPLEMENTATION")
    
-- Configure custom build events
after_build(function (target)
    -- Display build information
    print("\x1b[38;2;0;255;0m[" .. " 99%]:\x1b[0m " .. "Output directory: " .. target:targetdir())
    
    -- Get and display compiled file size
    local targetfile = target:targetfile()
    local filesize = os.filesize(targetfile)
    
    -- Format file size display
    local size_text = ""
    if filesize < 1024 then
        size_text = string.format("%.2f B", filesize)
    elseif filesize < 1024 * 1024 then
        size_text = string.format("%.2f KB", filesize / 1024)
    else
        size_text = string.format("%.2f MB", filesize / (1024 * 1024))
    end
    
    print("\x1b[38;2;0;255;0m[" .. " 99%]:\x1b[0m " .. "Size: " .. size_text)
end)

-- Custom menu
option("debug")
    set_default(false)
    set_showmenu(true)
    set_category("Options")
    set_description("Enable debug mode")
