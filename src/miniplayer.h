#ifndef MINIPLAYER_H
#define MINIPLAYER_H

#include <QMainWindow>
#include <QAbstractButton>

namespace Ui {
class MiniPlayer;
}

class MiniPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MiniPlayer(QWidget *parent = 0);
    ~MiniPlayer();

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void keyPressed(QKeyEvent *event);

public slots:
    void placeMiniPlayer(QPoint& pt);

    void nowPlaying(QString title, QString artist, QString album, int duration);
    void playbackTime(int current, int total);
    void rating(int rate);
    void albumArt(QPixmap pixmap);

    void repeat(QString mode);
    void shuffle(QString mode);

    void changeBackground();
    void enableBackground();
    void disableBackground();

    void activateWindow();
    void hide();
    void show();
    void raise();

    void bringToFront();

    void setBackgroundColor(QColor color);

    void isPlaying(int mode);
    void rewindEnabled(int mode);
    void forwardEnabled(int mode);

private:
    void invert(bool inv);
    void setIcon(QAbstractButton* button, QString base);

public:
    Ui::MiniPlayer *ui;

private:
    // This is a real hack
    // The mini player has two positions
    // - Invoked from the trayIcon
    // - Invoked when calling from the menus or shortcuts
    // We assume that when we invoke the mini player from the trayIcon
    // The timing to show it is less then 100ms.
    // Otherwise the userPosition is used
    //
    // Both points are initialized to (
    qint64 trayIconTiming;
    QPoint trayIconPosition;
    qint64 userIconTiming;
    QPoint userPosition;

    QPixmap album_picture;
    bool large;

    // Variables to drag the mini player without title bar
    bool do_move;
    int mouse_click_x_coordinate;
    int mouse_click_y_coordinate;

    // Set this when we inverted the colors
    bool inverted;
    QString _shuffle;
    QString _repeat;
    int _rating;
    QString style;
};

#endif // MINIPLAYER_H
