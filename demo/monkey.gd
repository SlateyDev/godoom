extends Node3D

@onready var main_shader = preload("res://main.tres")

var doomscreen : GodoomRef

var img : Image
var img_texture : ImageTexture

func _ready():
	img = Image.create(640, 400, false, Image.FORMAT_RGBA8)
	$Suzanne.mesh.surface_set_material(0, main_shader)
	img_texture = ($Suzanne.mesh.surface_get_material(0) as ShaderMaterial).get_shader_parameter("texture_albedo") as ImageTexture
	img_texture.set_image(img)
	doomscreen = GodoomRef.new()

func _process(delta):
	doomscreen.get_doom_image(img)
	img_texture.set_image(img)
	rotate_x(deg_to_rad(15 * delta))
	rotate_y(deg_to_rad(21 * delta))
	rotate_z(deg_to_rad(7 * delta))
