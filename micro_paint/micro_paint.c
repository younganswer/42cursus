#include "micro_paint.h"

t_bool	init_rectangle(Rectangle *info, FILE *fd);
t_bool	draw_border_only(Rectangle *info, Op *op);
t_bool	draw_filled_rectangle(Rectangle *info, Op *op);
t_bool	draw_board(Rectangle *info);

int	ft_ceil(float operand);
int	ft_floor(float operand);

int	main(int argc, char **argv) {
	if (argc != 2) {
		write(1, "Error: argument\n", 16);
		return (1);
	}

	FILE	*fd = fopen(argv[1], "r");
	if (!fd) {
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}

	Rectangle	*info = (Rectangle *) calloc(1, sizeof(Rectangle));
	if (!info) {
		write(1, "Error: Fail to calloc at info\n", 30);
		return (1);
	}
	if (!init_rectangle(info, fd))
		return (1);
	
	Op	*op = (Op *) calloc(1, sizeof(Op));
	if (!op) {
		write(1, "Error: Fail to calloc at op\n", 28);
		return (1);
	}
	while (fscanf(fd, "%s %f %f %f %f %s\n", &op->flag, &op->x, &op->y, &op->width, &op->height, &op->c) == 6) {
		if ((op->flag != 'r' && op->flag != 'R') || 
			(op->width <= 0 || op->height <= 0)) {
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		if (op->flag == 'r') {
			if (!draw_border_only(info, op)) {
				write(1, "Error: Operation file corrupted\n", 32);
				return (1);
			}
		} else if (op->flag == 'R') {
			if (!draw_filled_rectangle(info, op)) {
				write(1, "Error: Operation file corrupted\n", 32);
				return (1);
			}
		} else {
			write(1, "Error: Unexpected error\n", 25);
			return (1);
		}
	}
	draw_board(info);
	return (0);
}

t_bool	init_rectangle(Rectangle *info, FILE *fd) {
	fscanf(fd, "%d %d %s\n", &info->width, &info->height, &info->background_char);
	if ((info->width <= 0 || 300 < info->width) || 
		(info->height <= 0 || 300 < info->height)) {
		write(1, "Error: Operation file corrupted\n", 32);
		return (FALSE);
	}
	info->board = (unsigned char **) calloc(info->height, sizeof(unsigned char *));
	if (!info->board) {
		write(1, "Error: Fail to calloc at board\n", 32);
		return (FALSE);
	}
	for (int i=0; i<info->height; i++) {
		info->board[i] = (unsigned char *) calloc(info->width, sizeof(unsigned char));
		if (!info->board[i]) {
			write(1, "Error: Fail to calloc at board\n", 32);
			return (FALSE);
		}
	}
	for (int i=0; i<info->height; i++) {
		for (int j=0; j<info->width; j++) {
			info->board[i][j] = info->background_char;
		}
	}
	return (TRUE);
}

t_bool	draw_border_only(Rectangle *info, Op *op) {
	int startPosX = ft_ceil(op->x);
	int startPosY = ft_ceil(op->y);
	int endPosX = ft_floor(op->x + op->width);
	int endPosY = ft_floor(op->y + op->height);
	if ((info->width <= startPosX || info->height <= startPosY) || 
		(endPosX <= 0 || endPosY <= 0))
		return (TRUE);

	for (int i=startPosY; i<=endPosY; i++) {
		if (i < 0 || info->height <= i)
			continue;
		for (int j=startPosX; j<=endPosX; j++) {
			if ((i != startPosY && i != endPosY) && 
				(j != startPosX && j != endPosX))
				continue;
			if (j < 0 || info->width <= j)
				continue;
			info->board[i][j] = op->c;
		}
	}
	return (TRUE);
}

t_bool	draw_filled_rectangle(Rectangle *info, Op *op) {
	int startPosX = ft_ceil(op->x);
	int startPosY = ft_ceil(op->y);
	int endPosX = ft_floor(op->x + op->width);
	int endPosY = ft_floor(op->y + op->height);
	if ((info->width <= startPosX || info->height <= startPosY) || 
		(endPosX <= 0 || endPosY <= 0))
		return (TRUE);
	for (int i=startPosY; i<=endPosY; i++) {
		if (i < 0 || info->height <= i)
			continue;
		for (int j=startPosX; j<=endPosX; j++) {
			if (j < 0 || info->width <= j)
				continue;
			info->board[i][j] = op->c;
		}
	}
	return (TRUE);
}

t_bool	draw_board(Rectangle *info) {
	for (int i=0; i<info->height; i++) {
		for (int j=0; j<info->width; j++) {
			write(1, &info->board[i][j], 1);
		}
		write(1, "\n", 1);
	}
	return (TRUE);
}

int	ft_ceil(float operand) {
	return (((int)(operand * 10) % 10) ? (operand + 1) : operand);
}

int	ft_floor(float operand) {
	return ((operand < 0) ? (operand - 1) : operand);
}