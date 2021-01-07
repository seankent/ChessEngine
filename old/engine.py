##########
# import #
##########
import numpy as np

#########
# Chess #
#########
class GameState():
	def __init__(self):
		"""
		board - board is a 8x8 2D array, each element of the array 
		        is a 2 character string. The first character represents the
		        color of the piece ('b' or 'w') and the second character 
		        represents the type of piece ('K', 'Q', 'R', 'N', 'B', or 'p').
		        The string '--' represents an empty space.
		turn - turn is a one character string indicating the 
		"""
		self.board = np.array([
			['bR', 'bN', 'bB', 'bQ', 'bK', 'bB', 'bN', 'bR'],
			['bp', 'bp', 'bp', 'bp', 'bp', 'bp', 'bp', 'bp'],
			['--', '--', '--', '--', '--', '--', '--', '--'],
			['--', '--', '--', '--', '--', '--', '--', '--'],
			['--', '--', '--', '--', '--', '--', '--', '--'],
			['--', '--', '--', '--', '--', '--', '--', '--'],
			['wp', 'wp', 'wp', 'wp', 'wp', 'wp', 'wp', 'wp'],
			['wR', 'wN', 'wB', 'wQ', 'wK', 'wB', 'wN', 'wR']
		])
		self.turn = 'w'
		self.log = np.array([])