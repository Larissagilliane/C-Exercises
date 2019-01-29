#ifndef __REGISTRADORES_H__
#define __REGISTRADORES_H__

void ler_registradores(int r[]);

void estado_registradores(int r[], char sep=' ' , bool indices = false );

void estado_registradores(int r[], int (*v) (int*));

#endif /* __REGISTRADORES_H__ */