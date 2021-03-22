///< @file base_figure.h

/**
 @author Yaroslav, Roma, Anna

 BaseFigure - ������� ����� ������;
*/
class BaseFigure{   // ������� �����
 protected:
    /// ��� ������, 1 - ������ ������, 0 - ����� ������
    int type;
    /// ����� ������ �� ��������
    int x_cell;
    /// ����� ������ �� �������
    int y_cell;
    /// ���� ������� ������
    COLORREF main_color;
    /// ���� ��������� ������
    COLORREF side_color;
    /// ������ ��������� �����
    vector <int*> move_ability_cells;

 public:
    /// �����������
    BaseFigure(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0);
    void move(int x_cell0, int  y_cell0);
    /// ������� �������� ����������� ����
    virtual void count_move_ability_cells(vector<BaseFigure*> figures){}
    /// ������� ���������
    virtual void change(){}
    /// ������� ���������
    virtual void draw(int x, int y, int r){}
    /// ������� ��������� + ���������
    void update();

    int get_type();
    void set_type(int type0);
    int get_x_cell();
    void set_x_cell(int x_cell0);
    int get_y_cell();
    void set_y_cell(int y_cell0);
    vector <int*> get_move_ability_cells();
    void set_move_ability_cells(vector <int*> move_ability_cells0);
};

BaseFigure::BaseFigure(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0): type(type0), x_cell(x_cell0), y_cell(y_cell0), main_color(main_color0), side_color(side_color0){}
/**
 ������� �������� ����� �� ������� ����;
 \param x_cell0  - ����� ������ �� �������;
 \param y_cell0  - ����� ������ �� ������;
 ����������� x_cell � y_cell �������� x_cell0 � y_cell0 ��������������.
 */
void BaseFigure::move (int x_cell0, int y_cell0){
    x_cell = x_cell0;
    y_cell = y_cell0;
}
void BaseFigure::update(){
    //change();
    //draw();
}
/**
 �������, ������� ���������� ��� (type) ������ ;
*/
int BaseFigure::get_type(){
    return type;
}
/**
 �������, ������� ����������� ��� (type) ������ ;
 \param type0  - ��� ������
*/
void BaseFigure::set_type(int type0){
    type = type0;
}
/**
 �������, ������� ���������� �������� x_cell;
 */
int BaseFigure::get_x_cell(){
    return x_cell;
}
/**
 �������, ������� ����������� �������� x_cell;
 \param  x_cell0 - ����� ������ � �������
 */
void BaseFigure::set_x_cell(int x_cell0){
    x_cell = x_cell0;
}
/**
 �������, ������ ���������� �������� y_cell;
 */
int BaseFigure::get_y_cell(){
    return y_cell;
}
/**
 �������, ������� ����������� �������� y_cell;
 \param  y_cell0 - ����� ������ �� ������
 */
void BaseFigure::set_y_cell(int y_cell0){
    y_cell = y_cell0;
}
/**
  ���������� ������ ��������� �����;
*/
vector <int*> BaseFigure :: get_move_ability_cells(){
    return move_ability_cells;
}
/**
 �������, ������� ����������� �������� move_ability_cells;
 \param  move_ability_cells0 - ������ ������������ ����
 */
void BaseFigure::set_move_ability_cells(vector <int*> move_ability_cells0){
    move_ability_cells = move_ability_cells0;
}
