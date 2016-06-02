#include<QApplication>
#include<QWidget>
#include<QTimer>
#include<QMouseEvent>
#include<QKeyEvent>
#include<QPainter>
#include<QBrush>
#include<QPen>
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

extern "C" {
  StzQtWidget* QtWidget_new (QWidget* parent) {return new StzQtWidget(parent);}
  void QtWidget_delete (StzQtWidget* x){delete x;}
  void QtWidget_show (StzQtWidget* x){x->show();}
  void QtWidget_update (StzQtWidget* x){x->update();}
  void QtWidget_set_width (StzQtWidget* x, int width){x->width = width;}
  void QtWidget_set_height (StzQtWidget* x, int height){x->width = height;}
  void QtWidget_set_listener (StzQtWidget* x, int listener){x->listener = listener;}
  int QtWidget_listener (StzQtWidget* x){return x->listener;}
}

//============================================================
//==================== Timer =================================
//============================================================
extern "C" void call_function (int func);

StzQtTimer::StzQtTimer(int on_tick){
  callback = on_tick;
  connect(this, SIGNAL(timeout()), this, SLOT(tick()));
}

void StzQtTimer::tick(){
  call_function(callback);
}

extern "C" {
  StzQtTimer* QTimer_new (int func, int interval){
    StzQtTimer* t = new StzQtTimer(func);
    t->setInterval(interval);
    return t;
  }
  void QTimer_delete (StzQtTimer* t){delete t;}
  int QTimer_callback (StzQtTimer* t){return t->callback;}
  void QTimer_start (StzQtTimer* t){t->start();}
  void QTimer_stop (StzQtTimer* t){t->stop();}
}

//============================================================
//=================== C Bindings =============================
//============================================================

extern "C" {  
  QApplication* QApplication_new (int argc, char* argv[]){return new QApplication(argc, argv);}
  void QApplication_delete (QApplication* x){delete x;}
  int QApplication_exec (QApplication* x){return x->exec();}

  int QMouseEvent_x (QMouseEvent* e){return e->x();}
  int QMouseEvent_y (QMouseEvent* e){return e->y();}

  int QKeyEvent_key (QKeyEvent* e){return e->key();}

  QPainter* QPainter_new (QWidget* widget){return new QPainter(widget);}
  void QPainter_set_pen (QPainter* p, QPen* pen){p->setPen(*pen);}
  void QPainter_set_brush (QPainter* p, QBrush* brush){p->setBrush(*brush);}
  void QPainter_delete (QPainter* p){delete p;}
  void QPainter_set_opacity (QPainter* p, float opacity){p->setOpacity(opacity);}
  void QPainter_draw_line (QPainter* p, int x, int y, int x2, int y2){p->drawLine(x, y, x2, y2);}
  void QPainter_draw_rect (QPainter* p, int x, int y, int width, int height){p->drawRect(x, y, width, height);}
  void QPainter_draw_pixmap (QPainter* p, int x, int y, int width, int height, QPixmap* pixmap){p->drawPixmap(x, y, width, height, *pixmap);}

  QBrush* QBrush_new (){return new QBrush();}
  QBrush* QBrush_new_c (QColor* c){return new QBrush(*c);}
  void QBrush_delete (QBrush* b){delete b;}
  
  QColor* QColor_new (int r, int g, int b, int a){return new QColor(r, g, b, a);}
  void QColor_delete (QColor* c){delete c;}

  QPixmap* QPixmap_load (char* filepath){
    QPixmap* pixmap = new QPixmap();
    int r = pixmap->load(filepath);
    if(r) return pixmap;
    else return 0;
  }
  void QPixmap_delete (QPixmap* p){delete p;}
  int QPixmap_width (QPixmap* p){return p->width();}
  int QPixmap_height (QPixmap* p){return p->height();}

  QPen* QPen_new (QColor* c, int thickness){return new QPen(*c, thickness, Qt::SolidLine);}
  void QPen_delete (QPen* p){delete p;}
}
