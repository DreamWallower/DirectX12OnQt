#include "d3dx12widget.h"
#include "d3dx12widgetprivate.h"


D3DX12Widget::D3DX12Widget(QWidget *parent)
    : QWidget(*new D3DX12WidgetPrivate(this), parent, Qt::WindowFlags())
{
    setAttribute(Qt::WA_NativeWindow, true);
    setAttribute(Qt::WA_PaintOnScreen, true);
}

void D3DX12Widget::initialize()
{
    Q_D(D3DX12Widget);
    d->initialize();
}

void D3DX12Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    Q_D(D3DX12Widget);
    d->render();
    update();
}

void D3DX12Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    Q_D(D3DX12Widget);
    d->resize();
}
