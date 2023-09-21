/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "godoom.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

extern "C" {
	extern uint32_t* DG_ScreenBuffer;
}

using namespace godot;

void GodoomRef::get_doom_image(Ref<Image> img) {
	PackedByteArray dest;
	dest.resize(640 * 400 * 4);
	std::memcpy(dest.ptrw(), DG_ScreenBuffer, 640 * 400 * 4);
	img->set_data(640, 400, false, Image::Format::FORMAT_RGBA8, dest);
}

void GodoomRef::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_doom_image", "img"), &GodoomRef::get_doom_image);
	ClassDB::bind_method(D_METHOD("queue_key", "pressed", "keycode"), &GodoomRef::queue_key);
}
