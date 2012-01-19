
// Copyright (c) 2011-2012, Daniel M�ller <dm@g4t3.de>
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

#include "proceduralhimmel.h"

#include "astronomy.h"
#include "astronomyla.h"

#include "atmospheregeode.h"
#include "moongeode.h"
#include "starsgeode.h"
#include "galaxygeode.h"

#include <assert.h>


ProceduralHimmel::ProceduralHimmel()
:   AbstractHimmel()
,   m_astronomy(NULL)

,   m_atmosphere(NULL)
,   m_moon(NULL)
,   m_stars(NULL)
,   m_galaxy(NULL)
{
    m_astronomy = new Astronomy(); // LowAccuracyAstronomy();


    setCullingActive(false);

    m_atmosphere = new AtmosphereGeode(*this);
    m_moon = new MoonGeode(*this);
    m_stars = new StarsGeode(*this);

    addChild(m_atmosphere);
    addChild(m_moon);
    addChild(m_stars);
    //addChild(m_galaxy);
};


ProceduralHimmel::~ProceduralHimmel()
{
    delete m_astronomy;
};


void ProceduralHimmel::update()
{
    AbstractHimmel::update();
    astro()->update(t_aTime::fromTimeF(*getTime()));

    m_atmosphere->update();
    m_moon->update();
    m_stars->update();   
}


const float ProceduralHimmel::setLatitude(const float latitude)
{
    assert(m_astronomy);
    return m_astronomy->setLatitude(latitude);
}

const float ProceduralHimmel::getLatitude() const
{
    assert(m_astronomy);
    return m_astronomy->getLatitude();
}


const float ProceduralHimmel::setLongitude(const float longitude)
{
    assert(m_astronomy);
    return m_astronomy->setLongitude(longitude);
}

const float ProceduralHimmel::getLongitude() const
{
    assert(m_astronomy);
    return m_astronomy->getLongitude();
}
