add_rules("mode.release","mode.debug")
target("st_raw")
    set_kind("binary")
    add_files("day5/RMQ/st_raw.cpp")
    -- add_cxxflags("-DOIDEBUG")
    set_rundir("./day5/RMQ")

target("st_done")
    set_kind("binary")
    add_files("./day5/RMQ/st_done.cpp")

target("test")
    set_kind("binary")
    add_files("test.cpp")