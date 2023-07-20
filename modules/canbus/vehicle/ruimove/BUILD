load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "ruimove_vehicle_factory",
    srcs = [
        "ruimove_vehicle_factory.cc",
    ],
    hdrs = [
        "ruimove_vehicle_factory.h",
    ],
    deps = [
        ":ruimove_controller",
        ":ruimove_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "ruimove_message_manager",
    srcs = [
        "ruimove_message_manager.cc",
    ],
    hdrs = [
        "ruimove_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/ruimove/protocol:canbus_ruimove_protocol",
    ],
)

cc_library(
    name = "ruimove_controller",
    srcs = [
        "ruimove_controller.cc",
    ],
    hdrs = [
        "ruimove_controller.h",
    ],
    deps = [
        ":ruimove_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/ruimove/protocol:canbus_ruimove_protocol",
    ],
)

cpplint()
