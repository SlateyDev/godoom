extends MeshInstance3D

var doomscreen : GodoomRef

var img : Image
var img_texture : ImageTexture

@export var input_enabled : bool = false

func _ready():
	img = Image.create(640, 400, false, Image.FORMAT_RGBA8)
	img_texture = (mesh.surface_get_material(0) as ShaderMaterial).get_shader_parameter("texture_albedo") as ImageTexture
	img_texture.set_image(img)
	doomscreen = GodoomRef.new()

func _process(delta):
	doomscreen.get_doom_image(img)
	img_texture.set_image(img)
	rotate_x(deg_to_rad(15 * delta))
	rotate_y(deg_to_rad(21 * delta))
	rotate_z(deg_to_rad(7 * delta))

func _input(event):
	if !input_enabled:
		return
		
	if event is InputEventKey:
		var keycode : int
		print(event.keycode & 255, ", ", event.unicode)
		match event.keycode:
			KEY_ENTER:
				keycode = 0x0D
			KEY_SPACE:
				keycode = 0x20
			KEY_ESCAPE:
				keycode = 0x1B
			KEY_LEFT:
				keycode = 0x25
			KEY_RIGHT:
				keycode = 0x27
			KEY_UP:
				keycode = 0x26
			KEY_DOWN:
				keycode = 0x28
			KEY_CTRL:
				keycode = 0x11
			KEY_SHIFT:
				keycode = 0x10
			_:
				keycode = event.keycode
		doomscreen.queue_key(1 if event.is_pressed() else 0, keycode)
