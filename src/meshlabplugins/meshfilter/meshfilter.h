/****************************************************************************
**
** Copyright (C) 2005-2005 Trolltech AS. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
** information about Qt Commercial License Agreements.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/
/* History
$Log$
Revision 1.28  2006/04/12 15:12:18  cignoni
Added Filter classes (cleaning, meshing etc)

Revision 1.27  2006/02/21 15:24:47  mariolatronico
case typo on #include

Revision 1.26  2006/02/20 21:11:36  giec
bugfix

Revision 1.25  2006/02/20 20:52:37  giec
replace refine and detacher dialog whit GnericELDialog

Revision 1.24  2006/02/06 10:18:27  mariolatronico
reverted to old behaviour, removed QEdgeLength

Revision 1.23  2006/02/05 11:22:40  mariolatronico
changed spinbox to QEdgeLength widget

Revision 1.22  2006/01/31 14:40:40  mariolatronico
removed unused variable ActionInfo *ai, added Log history

*/


#ifndef EXTRAFILTERSPLUGIN_H
#define EXTRAFILTERSPLUGIN_H

#include <QObject>
#include <QStringList>
#include <QList>

#include <meshlab/meshmodel.h>
#include <meshlab/interfaces.h>
#include "decimatorDialog.h"
#include "transformDialog.h"
#include "../../meshlab/GenericELDialog.h"
#include "../../meshlab/GLLogStream.h"

class ExtraMeshFilterPlugin : public QObject, public MeshFilterInterface
{
	Q_OBJECT
	Q_INTERFACES(MeshFilterInterface)

		public:
	/* naming convention :
		 - FP -> Filter Plugin
		 - name of the plugin separated by _
	*/
	enum FilterType { FP_LOOP_SS, 
                    FP_BUTTERFLY_SS, 
                    FP_REMOVE_UNREFERENCED_VERTEX,
										FP_REMOVE_DUPLICATED_VERTEX, 
                    FP_REMOVE_NULL_FACES,
										FP_LAPLACIAN_SMOOTH, 
                    FP_DECIMATOR, 
                    FP_MIDPOINT, 
                    FP_REORIENT ,
                    FP_INVERT_FACES,
										FP_TRANSFORM, 
                    FP_REMOVE_SMALL_FACES	} ;

	const QString ST(FilterType filter);
  const FilterType ID(QAction *a);

  virtual QList<FilterType> &types() { return typeList;}

	ExtraMeshFilterPlugin();
	~ExtraMeshFilterPlugin();
	virtual const ActionInfo &Info(QAction *);
	virtual const PluginInfo &Info();
  virtual const FilterClass getClass(QAction *);

	virtual QList<QAction *> actions() const;
	bool applyFilter(QAction *filter, MeshModel &m, QWidget *parent, vcg::CallBackPos * cb) ;
	void setLog(GLLogStream *log) { this->log = log ; }
protected:
	GLLogStream *log;
	QList <QAction *> actionList;
	QList <FilterType> typeList;

//	RefineDialog *refineDialog;
	DecimatorDialog *decimatorDialog;
	TransformDialog *transformDialog;
	GenericELDialog *genericELD;
};

#endif
