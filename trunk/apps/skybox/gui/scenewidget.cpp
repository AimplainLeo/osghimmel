
// Copyright (c) 2011, Daniel M�ller <dm@g4t3.de>
// Computer Graphics Systems Group at the Hasso-Plattner-Institute, Germany
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright 
//     notice, this list of conditions and the following disclaimer in the 
//     documentation and/or other materials provided with the distribution.
//   * Neither the name of the Computer Graphics Systems Group at the 
//     Hasso-Plattner-Institute (HPI), Germany nor the names of its 
//     contributors may be used to endorse or promote products derived from 
//     this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#include "scenewidget.h"

#include "abstracthimmelscene.h"

#include <QVBoxLayout>

#include <qtpropertybrowser/QtTreePropertyBrowser>


// EffectPropertyWidget

SceneWidget::SceneWidget(QWidget *parent)
:	QWidget(parent)
,   m_scene(NULL)
,   m_propertyBrowser(NULL)
{
    setWindowTitle("Properties");

	// setup property browser and stuff
	m_propertyBrowser = new QtTreePropertyBrowser(this);
	m_propertyBrowser->setResizeMode(QtTreePropertyBrowser::Interactive);
	m_propertyBrowser->setStyleSheet("QTreeView { alternate-background-color: #e6ebf2; background-color: #f2f4f8; }");
	m_propertyBrowser->setAlternatingRowColors(true);

	// setup ui
	setLayout(new QVBoxLayout(this));
	layout()->setSpacing(4);
	layout()->setMargin(4);

	layout()->addWidget(m_propertyBrowser);

	setDisabled(true);
}


SceneWidget::~SceneWidget()
{

}


void SceneWidget::setScene(AbstractHimmelScene *scene)
{
	if(m_scene)
		m_scene->clearPropertyBrowser(m_propertyBrowser);

	m_scene = scene;

	setDisabled(m_scene == NULL);

	if(m_scene)
		m_scene->floodPropertyBrowser(m_propertyBrowser);
}
