#include<QApplication>
#include<QWidget>

//============================================================
//==================== Widget ================================
//============================================================

class StzQtWidget : public QWidget{
  Q_OBJECT
 public:
  StzQtWidget(QWidget* parent);
  int width;
  int height;
  int listener;
  QSize sizeHint() const;
 protected:
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);  
  void keyPressEvent(QKeyEvent *event);
};
