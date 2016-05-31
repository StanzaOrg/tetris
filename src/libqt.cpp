#include<QApplication>
#include<QWidget>
#include "libqt.h"

//============================================================
//==================== Widget ================================
//============================================================

StzQtWidget::StzQtWidget(QWidget* parent) : QWidget(parent) {
  width = 100;
  height = 100;
  listener = -1;
}

QSize StzQtWidget::sizeHint() const{
  return QSize(width, height);
}

extern "C" void QtWidget_paintEvent (int listener, QPaintEvent* event);
extern "C" void QtWidget_mousePressEvent (int listener, QMouseEvent* event);
extern "C" void QtWidget_mouseReleaseEvent (int listener, QMouseEvent* event);
extern "C" void QtWidget_mouseMoveEvent (int listener, QMouseEvent* event);
extern "C" void QtWidget_keyPressEvent (int listener, QKeyEvent* event);

void StzQtWidget::paintEvent(QPaintEvent* event){
  QtWidget_paintEvent(listener, event);
}

void StzQtWidget::mousePressEvent(QMouseEvent* event){
  QtWidget_mousePressEvent(listener, event);
}
void StzQtWidget::mouseReleaseEvent(QMouseEvent* event){
  QtWidget_mouseReleaseEvent(listener, event);
}
void StzQtWidget::mouseMoveEvent(QMouseEvent* event){
  QtWidget_mouseMoveEvent(listener, event);
}

void StzQtWidget::keyPressEvent(QKeyEvent *event){
  QtWidget_keyPressEvent(listener, event);
}

//============================================================
//=================== C Bindings =============================
//============================================================

extern "C" {  
  QApplication* QApplication_new (int argc, char* argv[]){return new QApplication(argc, argv);}
  void QApplication_delete (QApplication* x){delete x;}
  int QApplication_exec (QApplication* x){return x->exec();}

  StzQtWidget* QtWidget_new (QWidget* parent) {return new StzQtWidget(parent);}
  void QtWidget_delete (StzQtWidget* x){delete x;}
  void QtWidget_show (StzQtWidget* x){x->show();}
  void QtWidget_set_width (StzQtWidget* x, int width){x->width = width;}
  void QtWidget_set_height (StzQtWidget* x, int height){x->width = height;}
  void QtWidget_set_listener (StzQtWidget* x, int listener){x->listener = listener;}
}
