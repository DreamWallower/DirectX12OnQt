#pragma once

#include <QWidget>



class D3DX12WidgetPrivate;
class D3DX12Widget final : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(D3DX12Widget)

public:
    explicit D3DX12Widget(QWidget* parent = nullptr);

    void initialize();

protected:
    // Disable Qt internal rendering process.
    QPaintEngine *paintEngine() const  { return nullptr; }

    // Handle painter event.
    virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    // Handle resize event.
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
};

