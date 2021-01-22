#include "d3dx12widget.h"
#include "d3dx12widgetprivate.h"


D3DX12Widget::D3DX12Widget(QWidget *parent)
    : QWidget(*new D3DX12WidgetPrivate(this), parent, Qt::WindowFlags())
{
    setAttribute(Qt::WA_NativeWindow, true);
    setAttribute(Qt::WA_PaintOnScreen, true);
}

void D3DX12Widget::Initialize()
{
    d_func()->Initialize();
}

void D3DX12Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    d_func()->Render();
    update();
}
