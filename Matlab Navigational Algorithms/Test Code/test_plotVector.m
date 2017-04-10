% Vector Struct
f5 = 'x0'; v5 = 0;
f6 = 'x1'; v6 = 0;
f7 = 'y0'; v7 = 0;
f8 = 'y1'; v8 = 0;
f9 = 'magnitude'; v9 = 0;
f10 = 'angle'; v10 = 0;
vectorTemplate = struct(f5,v5,f6,v6,f7,v7,f8,v8,f9,v9,f10,v10);

vector1 = struct(vectorTemplate);
vector1.x0 = 10;
vector1.x1 = 30;
vector1.y0 = 10;
vector1.y1 = 50;

plot([vector1.x0, vector1.x1], [vector1.y0, vector1.y1], 'k');