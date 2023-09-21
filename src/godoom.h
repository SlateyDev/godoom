#ifndef GODOOM_CLASS_H
#define GODOOM_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

extern "C" {
	extern void addKeyToQueue(int pressed, unsigned char keyCode);
}

using namespace godot;

class GodoomRef : public RefCounted {
	GDCLASS(GodoomRef, RefCounted);

protected:
	static void _bind_methods();

public:
	GodoomRef() {}
	~GodoomRef() {}

	void get_doom_image(Ref<Image> image);
	void queue_key(int pressed, int keycode) {
		addKeyToQueue(pressed, (unsigned char)keycode);
	}
};

#endif // GODOOM_CLASS_H
