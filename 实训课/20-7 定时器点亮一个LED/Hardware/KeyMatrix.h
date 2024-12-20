#ifndef __KEYMATRIX_H
#define __KEYMATRIX_H

#define KEY_MATRIX_PORT P1
//行扫描
u8 key_matrix_ranks_scan(void);
//线反转扫描
u8 key_matrix_flip_scan(void);

#endif