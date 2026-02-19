dir = include_directories('.')
cc = meson.get_compiler('c')
add_project_arguments('-D_POSIX_C_SOURCE=200112L', language: 'c')
add_project_arguments('-D_POSIX_C_SOURCE=200112L', language: 'cpp')

fossil_type_lib = library('fossil_type',
    files(
        'feature.c',
        'tribool.c',
        'limits.c'
    ),
    install: true,
    dependencies: [cc.find_library('m', required: false)],
    include_directories: dir)

fossil_type_dep = declare_dependency(
    link_with: [fossil_type_lib],
    include_directories: dir)

meson.override_dependency('fossil-type', fossil_type_dep)