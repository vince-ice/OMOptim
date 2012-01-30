// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR 
 * THIS OSMC PUBLIC LICENSE (OSMC-PL). 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE. 
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or  
 * http://www.openmodelica.org, and in the OpenModelica distribution. 
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)

  @file MOParametersDlg.h
  @brief Comments for file documentation.
  @author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
  Company : CEP - ARMINES (France)
  http://www-cep.ensmp.fr/english/
  @version
*/

#if !defined(_MOParametersDlg_H)
#define _MOParametersDlg_H

#include <QtGui/QWidget>
#include <QtGui/QDialog>
#include <QtGui/QSortFilterProxyModel>
#include <QtGui/QHeaderView>
#include <QtGui/QSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QComboBox>
#include <QtCore/QObject>
#include <QtCore/QObjectList>
#include <QtCore/QVariantList>
#include <QtCore/QStringList>
#include <QtCore/QVector>
#include <QtGui/QTabWidget>

#include "MOParameter.h"
#include "Tools/GuiTools.h"
#include "MOVector.h"




class MOParametersDlg : public QDialog
{
    Q_OBJECT

public:
    MOParametersDlg(MOParameters *parameters, bool editable=true);


protected :
    QMap<QPushButton*,QLineEdit*> _pathsMap;
    MOParameters *_localParameters;
    MOParameters *_orgParameters;
    QMap<MOParameter*,QWidget*> _mapValueWidgets;
    QStringList _paramNames;
    QVector<int> _paramTypes;
    bool _editable;

    QGridLayout* buildLayoutFromParameters();
    void updateEnabled();
    QVariant getValue(QWidget* curWidget);
    void setValue(QWidget* curWidget,QVariant value);

public slots:
    virtual void pushedOk();
    void pushedCancel();
    void pushedDefault();
    void onValueChanged();
    void onSelectFileClicked();
    void onSelectFolderClicked();



};



#endif