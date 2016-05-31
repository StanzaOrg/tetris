#include<QApplication>
#include<QWidget>

//============================================================
//==================== Widget ================================
//============================================================

class StzQtWidget : public QWidget{
  Q_OBJECT
 public:
  StzQtWidget(QWidget* parent);
/*
  QSize sizeHint() const;
  int paintEventListener;
  int mousePressEventListener;
  int mouseReleaseEventListener;
  int mouseMoveEventListener;
  int keyEventListener;
  int width_hint;
  int height_hint;
 protected:
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);  
  void keyPressEvent(QKeyEvent *event);
  */
};
