///< @file Bishop.h

/**
 @author Roma, Artiom, Timofey

 Bishop - ����� ������ �����;

 ������� ������ BaseFigure.
*/
class Bishop: public BaseFigure{
 public:
    /// �����������
    Bishop(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}

    virtual void draw(int x, int y, int r) override;                                          // ���������
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;              // ������� ����������� �����
    virtual void change() override{}
};
/**
 ������� ��������� �����;
 \param x  - ���������� ����� �� ��� x;
 \param y  - ���������� ����� �� ��� y;
 \param r  - ������ �����.
 */
void Bishop::draw(int x, int y, int r){
    txSetColor (side_color, 0.5);
    txSetFillColor (main_color);
    txEllipse (x + 1 * r, y - 7.4 * r, x + 3.9 * r,  y - 6.4 * r);    // 3 ���� ������
    txEllipse (x + 1 * r, y - 10.15 * r, x + 3.9 * r,  y - 7.15 * r); // 2 ���� ������
    txEllipse (x + 2 * r, y - 10.65 * r, x + 2.9 * r,  y - 10.1 * r); // 1 ���� ������

    POINT body[4] = {{long(19/10.*r)+x, (-7*r)+y}, {long(29/10.*r)+x, (-7*r)+y}, {long(49/10.*r)+x, (3*r)+y}, {long(-1/10.*r)+x, (3*r)+y}}; // ������������ ����
    txPolygon (body, 4);

    POINT stand1[4] = {{long(-11/10.*r)+x, (3*r)+y}, {long(59/10.*r)+x, (3*r)+y}, {long(59/10.*r)+x, (4*r)+y}, {long(-11/10.*r)+x, (4*r)+y}}; // ������ ��������� ��� ����, � � ����� ������ ���
    txPolygon (stand1, 4);

    POINT stand2[4] = {{long(-21/10.*r)+x, (4*r)+y}, {long(69/10.*r)+x, (4*r)+y}, {long(69/10.*r)+x, (5*r)+y}, {long(-21/10.*r)+x, (5*r)+y}}; // ������ ��������� ��� �������(�����,����,����) � ������
    txPolygon (stand2, 4);
    txSetColor (TX_BLACK, 0.085 * r);
    txLine (x + 3.1 * r, y - 10 * r, x + 2.4 * r, y - 8.8 * r);
    txLine (x + 2.4 * r, y - 8.8 * r, x + 2.7 * r, y - 8.65 * r);
    txLine (x + 2.7 * r, y - 8.65 * r, x + 3.359 * r, y - 9.8 * r);
}
/**
 ������� �������� ����������� ����;
 \param figures  - ������ �����.
 ���� ����� � ��� �� ���������� �� ����� ���������� ������;
*/
void Bishop :: count_move_ability_cells(vector<BaseFigure*> figures) {
    move_ability_cells.clear();
    bool out = false;
    for(int i = 1; (y_cell - i >= 0) && (x_cell + i < 8); i++) {   // ����� ������
        int* cell = new int[2];
        cell[0] = y_cell - i;
        cell[1] = x_cell + i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - i)) && (figura->get_x_cell() == (x_cell + i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int i = 1; (y_cell - i >= 0) && (x_cell - i >= 0); i++) {  // ����� �����
        int* cell = new int[2];
        cell[0] = y_cell - i;
        cell[1] = x_cell - i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - i)) && (figura->get_x_cell() == (x_cell - i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
    out = false;
    for(int i = 1; (y_cell + i < 8) && (x_cell + i < 8); i++) {    // ���� ������
        int* cell = new int[2];
        cell[0] = y_cell + i;
        cell[1] = x_cell + i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + i)) && (figura->get_x_cell() == (x_cell + i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
    out = false;
    for(int i = 1; (y_cell + i < 8) && (x_cell - i >= 0); i++) {   // ���� �����
        int* cell = new int[2];
        cell[0] = y_cell + i;
        cell[1] = x_cell - i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + i)) && (figura->get_x_cell() == (x_cell - i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
}
