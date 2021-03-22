///< @file pawn_to_queen.h

#include <TXlib.h>
/// @author ����� ������
/// \version 2.0
/// \data 12.03.21

/// \brief   ��� ������� ����������� ����� � �����
/// \details ��� ������� ������������� ��� ����, ����� ����� ����� �������� ����� ���� ��� ����� ����� ������

void pawn_to_queen()
{
    bool broken = false; // ���������� ���������� �� �� ������� ������ ��� ��� (����� ����� ���������� ������ ��� �� ������ �������� � ����� ������), ���������� true
    bool queen = false; // ���������� ���������� �� �� ������ �� �����

    auto pPawn = dynamic_cast<Pawn>(pOther); // ������� ���������
    if pPawn //���� �����
    {
        int y = pPawn->get_y_cell()
        int x = pPawn->get_x_cell()

        if(y == 0) // ���� ����� ����� ���������� y == 0
        {
            if queen // ���� ������ �����
            {
                // ������� ����� �� ����� �����
                figures.push_back(new Queen(0, x, 0));
                cells[0][x]->set_figure(figures.back());
            }
        }
        else if(y == 7) // ���� ����� i ����� ���������� y == 7
        {
            if queen // ���� ������ �����
            {
                // ������� ����� �� ����� �����
                figures.push_back(new Queen(1, x, 7));
                cells[7][x]->set_figure(figures.back());
            }
        }
    }
}
