// static t_point	get_iso_point_to_draw(t_mlx *m, int i)
// {
// 	double		rm[16];
// //	double		angle = 26.57;
// 	t_point		p;
// 	double		angle = 26.57 * M_PI / 180.0;


// 	p = m->map_points[i];
// //	set_rotate_matrix_to_one(rm);
// 	set_rotate_matrix_zero(rm);
// 	rm[0] = cos(angle);
// 	rm[1] = sin(angle);
// 	rm[4] = -cos(angle);
// 	rm[5] = sin(angle);
// 	rm[9] = -1;
// //	rm[3] = 0.15;
// 	rm[15] = 1;
// 	mult_xyz_rmatrix(m, rm, &p);


// 	p = m->map_points[i];
// 	set_rotate_matrix_to_one(rm);
// //	set_rotate_matrix_zero(rm);
// 	rm[10] = 1;
// 	// rm[0] = cos(angle);
// 	// rm[1] = sin(angle);
// 	// rm[4] = -cos(angle);
// 	// rm[5] = sin(angle);
// 	rm[11] = -0.01;
// 	rm[15] = 1;
// // 	rm[9] = -1;
// // //	rm[3] = 0.15;
// // 	rm[15] = 1;
// 	mult_xyz_rmatrix_persp(m, rm, &p);

// 	return (p);
// }


void			mult_xyz_rmatrix_persp(t_mlx *m, double *rmatrix, t_point *p)
{
	t_point		prev;
	double		tmp;

	prev = *p;
	prev.x -= m->width / 2;
	prev.y -= m->height / 2;
	p->x = prev.x * rmatrix[0] + prev.y * rmatrix[4] + prev.z * rmatrix[8] + 1 * rmatrix[12];
	p->y = prev.x * rmatrix[1] + prev.y * rmatrix[5] + prev.z * rmatrix[9] + 1 * rmatrix[13];
	p->z = prev.x * rmatrix[2] + prev.y * rmatrix[6] + prev.z * rmatrix[10] + 1 * rmatrix[14];
	tmp = prev.x * rmatrix[3] + prev.y * rmatrix[7] + prev.z * rmatrix[11] + 1 * rmatrix[15];
	p->x = p->x / (tmp);
	p->y = p->y / (tmp);
	p->z = p->z / (tmp);
	p->x += m->width / 2;
	p->y += m->height / 2;
}

void			rotate_points(t_mlx *m)
{
	t_rot	mr;
	int		i;

	m->mr = &mr;
	correct_angles(m);
	calc_r_x_y_z(m, &mr);
	set_rotate_matrix_to_one(mr.r_all);
	mult_rmatrix(mr.r_all, mr.r_all, mr.r_x);
	mult_rmatrix(mr.r_all, mr.r_all, mr.r_y);
	mult_rmatrix(mr.r_all, mr.r_all, mr.r_z);
	i = -1;
	while (++i < m->quantity_points)
		mult_xyz_rmatrix(m, mr.r_all, &(m->map_points[i]));
	// set_rotate_matrix_to_one(mr.r_persp);
	// mr.r_persp[11] = -1/10.0;

	// mr.r_persp[15] = 1;
	// i = -1;
	// while (++i < m->quantity_points)
	//  	mult_xyz_rmatrix_persp(m, mr.r_persp, &(m->map_points[i]));
}
