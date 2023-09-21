/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "godoom.h"
#include "tests.h"

extern "C" {
	void D_DoomMain(void);
	void dg_Create();
}

void DoomStart() {
	dg_Create();
	D_DoomMain ();
}

using namespace godot;

void initialize_godoom_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<GodoomRef>();

	// start doom
	printf("Starting D_DoomMain\r\n");

	doom_thread = new std::thread(DoomStart);
}

void uninitialize_godoom_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	delete doom_thread;
}

extern "C" GDExtensionBool GDE_EXPORT godoom_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library,
                                                           GDExtensionInitialization *r_initialization) {

	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_godoom_module);
    init_obj.register_terminator(uninitialize_godoom_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}