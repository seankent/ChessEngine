##########
# import #
##########
import numpy as np
import pygame
from engine import *

##############
# parameters #
##############
WIDTH = HEIGHT = 512
DIMENSIONS = 8
SQUARE_SIZE = HEIGHT//DIMENSIONS
MAX_FPS = 15
IMAGES = {}
BOARD_COLORS = np.array([pygame.Color('white'), pygame.Color('gray')])


###############
# load_images #
###############
def load_images():
	"""
	Initializes a global dictonary of images.
	"""
	pieces = ['wK', 'wQ', 'wR', 'wN', 'wB', 'wp', 'bK', 'bQ', 'bR', 'bN', 'bB', 'bp']
	for piece in pieces:
		IMAGES[piece] = pygame.transform.scale(pygame.image.load('images/{}.png'.format(piece)), (SQUARE_SIZE, SQUARE_SIZE))

###################
# draw_game_state #
###################
def draw_game_state(screen, gs):
	"""
	Responsible for all graphics within the current game state.
	"""
	draw_board(screen)
	draw_pieces(screen, gs)

##############
# draw_board #
##############
def draw_board(screen):
	"""
	Draws squares on the board.
	"""
	for row in range(DIMENSIONS):
		for col in range(DIMENSIONS):
			color = BOARD_COLORS[(row + col)%2]
			pygame.draw.rect(screen, color, pygame.Rect((col*SQUARE_SIZE, row*SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE)))


###############
# draw_pieces #
###############
def draw_pieces(screen, gs):
	"""
	Draws pieces on the board.
	"""
	for row in range(DIMENSIONS):
		for col in range(DIMENSIONS):
			piece = gs.board[row][col]
			if piece != '--':
				screen.blit(IMAGES[piece], pygame.Rect((col*SQUARE_SIZE, row*SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE)))

########
# main #
########
def main():
	pygame.init()
	screen = pygame.display.set_mode((WIDTH, HEIGHT))
	clock = pygame.time.Clock()
	screen.fill(pygame.Color('white'))
	gs = GameState()
	load_images()
	running = True
	while running:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				running = False
		draw_game_state(screen, gs)
		clock.tick(MAX_FPS)
		pygame.display.flip()

if __name__ == '__main__':
	main()
