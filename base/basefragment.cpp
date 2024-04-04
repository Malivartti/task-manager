#include "basefragment.h"

BaseFragment::BaseFragment() {}
BaseFragment::BaseFragment(QWidget *parent) : QDialog(parent) {}
BaseFragment::~BaseFragment() {}
void BaseFragment::onPause() {}
void BaseFragment::onResume() {}
void BaseFragment::setData(BaseModel* model) {}
