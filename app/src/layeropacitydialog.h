#ifndef LAYEROPACITYDIALOG_H
#define LAYEROPACITYDIALOG_H

#include <QDialog>
#include "editor.h"

class QTimer;
class LayerManager;
class PlaybackManager;

namespace Ui {
class LayerOpacityDialog;
}

class LayerOpacityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LayerOpacityDialog(QWidget *parent = nullptr);
    ~LayerOpacityDialog();

    void setCore(Editor* editor);
    void init();
    void initBitmap();
    void initVector();

private slots:
    void opacitySliderChanged(int value);
    void opacitySpinboxChanged(double value);
    void allLayerOpacity();
    void selectedKeyframesOpacity();
    void fadeInPressed();
    void fadeOutPressed();

    void newFileLoaded();
    void currentLayerChanged(int index);
    void currentFrameChanged(int frame);
    void selectedFramesChanged();
    void playStateChanged(bool isPlaying);

signals:
    void closedialog();

private:

    void updateSlider();
    void opacityValueChanged();
    void setOpacityCurrentKeyframe();
    void setOpacitySelectedKeyframes();
    void setOpacityLayer();
    void enableDialog();
    void disableDialog();
    void closeClicked();

    Ui::LayerOpacityDialog *ui;

    Editor* mEditor = nullptr;
    LayerManager* mLayerManager = nullptr;
    PlaybackManager* mPlayBack = nullptr;

    bool mOpacityChanges = false;
    bool mPlayerIsPlaying = false;
};

#endif // LAYEROPACITYDIALOG_H
