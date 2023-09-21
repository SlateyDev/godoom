@tool
extends TextureRect

var doomscreen : GodoomRef

var img : Image
var img_texture : ImageTexture

func _ready():
	img = Image.create(640, 400, false, Image.FORMAT_RGBA8)
	img_texture = ImageTexture.new()
	img_texture.set_image(img)
	# texture = img_texture
	doomscreen = GodoomRef.new()

func _process(delta):
	queue_redraw()
#	texture = tex
	pass

func _draw():
	doomscreen.get_doom_image(img)
	img_texture.set_image(img)
	draw_texture(img_texture, Vector2(0, 0), Color.RED)
