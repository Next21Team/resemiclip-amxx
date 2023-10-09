project('ReSemiclip', 'cpp')

cppflags = [
    '-std=c++17',
    '-D_vsnprintf=vsnprintf',
    '-m32',
    '-w'
]

ldflags = '-m32'

inc = include_directories(
    '.',
    'include',
    'cssdk/common',
    'cssdk/dlls',
    'cssdk/engine',
    'cssdk/game_shared',
    'cssdk/pm_shared',
    'cssdk/public',
    'metamod'
)

src = [
    'src/h_export.cpp',
    'src/gamedll_api.cpp',
    'src/engine_rehlds_api.cpp',
    'src/meta_api.cpp',
    'src/main.cpp',
    'src/config.cpp',
    'src/amxxmodule.cpp',
    'src/natives.cpp',
    'cssdk/public/interface.cpp'
]

cpp = meson.get_compiler('cpp')
dl = cpp.find_library('dl')

shared_library('resemiclip', src, include_directories: inc, cpp_args: cppflags, link_args: ldflags, dependencies: dl)