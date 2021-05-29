
#include "cub3d.h"

void	draw_point(int x, int y, int rgb, t_g *g)
{
	my_pixel_put(&(g->win), x, y, rgb);
}

void	dx_sup_dy(t_vector *p0, t_vector *p1, int rgb, t_g *g)
{
	int	dx;
	int	dy;
	int	e;
	
	e = p1->x - p0->x;
	dx = e * 2;
	dy = dy * 2;
	while (1)
	{
		draw_point(p0->x, p0->y, rgb, g);
		if ((p0->x++) == p1->x)
			break;
		if ((e = e - dy) < 0)
		{
			p0->y++;
			e += dx;
		}
	}
}

void	dx_inf_dy(t_vector *p0, t_vector *p1, int rgb, t_g *g)
{
	int	dx;
	int	dy;
	int	e;
	
	e = p1->y - p0->y;
	dy = e * 2;
	dx = dx * 2;
	while (p0->y == p1->y)
	{
		draw_point(p0->x, p0->y, rgb, g);
		p0->y++;
		if ((e -= dx) < 0)
		{
			p0->x++;
			e += dy;
		}
}
void	dx_sup_neg_dy(t_vector *p0, t_vector *p1, int rgb, t_g *g)
{
	int	dx;
	int	dy;
	int	e;

	e = p1->x - p0->x;
	dx = e * 2;
	dy *= 2;
	while (1)
	{
		draw_point(p0->x, p0->y, rgb, g);
		if ((p0->x++) == p1->x)
			break;
		if ((e = e + dy) < 0)
		{
			p0->y--;
			e += dx;
		}
	}
}

void	dx_inf_neg_dy(t_vector *p0, t_vector *p1, int rgb, t_g *g)
{
	int	dx;
	int	dy;
	int	e;

	e = p1->y - p0->y;
	dy = e * 2;
	dx *= 2;
	while (1)
	{
		draw_point(p0->x, p0->y, rgb, g);
		if ((p0->y--) == p1->y)
			break;
		if ((e = e + dx) > 0)
		{
			p0->x++;
			e += dy;
		}
	}
}


void	dx_positive(t_vector *p0, t_vector *p1, int rgb, t_g *g)
{
	int	dx;
	int	dy;
	
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dy != 0)
	{
		if (dy > 0)
		{
			if (dx >= dy)
				dx_sup_dy(&p0, &p1, rgb, g);	
			else
				dx_inf_dy(&p0, &p1, rgb, g);
		}
		else
		{
			if (dx >= -dy)
				dx_sup_neg_dy(&p0, &p1, rgb, g);
			else
				dx_inf_neg_dy(&p0, &p1, rgb, g);
		}
	}
	else
	{
		while (p0->x++ != p1->x)
			draw_point(p0->x, p0->y, rgb, g);
	}
}

void	end(t_vector *p0, t_vector *p1, int rgb, t_g *g)
{
	int	dy;

	dy = p1->y - p0->y;
	if (dy != 0)
	{
		if (dy > 0)
			while (p0->y++ != p1->y)
				draw_point(p0->x, p0->y, rgb, g);
		else
			while (p0->y-- != p1->y)
				draw_point(p0->x, p0->y, rgb, g);
	}
}

void	draw_line(t_vector p0, t_vector p1, t_g *g, int rgb)
{
	int		dx;

	dx = p1->x - p0->x;
	if (dx != 0)
	{
		if (dx > 0)
			dx_positive(&p0, &p1, rgb, g);
		else
			dx_negative(&p0, &p1, rgb, g);
	}
	else
		end(&p0, &p1, rgb, g);
}

void	drawline(t_vector *a, t_vector *b)
{
	if (a.x > a.y)
	{
		if (a.x >= b.x)
		{

		}
		else if (a.x < b.x)
		{

		}
	}
	else if (a.x < a.y)
	{
		if (a.y > b.y)
		{

		}
		else if (a.y < b.y)
		{
			
		}
	}
}