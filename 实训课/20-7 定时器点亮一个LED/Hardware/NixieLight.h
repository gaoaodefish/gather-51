#ifndef	__NIXIELIGHT_H
#define __NIXIELIGHT_H

#define SMG_DYMANIC_PORT P0
#define SMG_STATIC_PORT P0

//静态数码管显示函数
void smg_static_display(u8 duan);

//动态数码管显示函数
void smg_dymanic_display(u8 wei,duan);

#endif