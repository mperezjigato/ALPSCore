/*****************************************************************************
*
* ALPS Project: Algorithms and Libraries for Physics Simulations
*
* ALPS Libraries
*
* Copyright (C) 2001-2004 by Matthias Troyer <troyer@comp-phys.org>,
*                            Synge Todo <wistaria@comp-phys.org>
*
* This software is part of the ALPS libraries, published under the ALPS
* Library License; you can use, redistribute it and/or modify it under
* the terms of the license, either version 1 or (at your option) any later
* version.
* 
* You should have received a copy of the ALPS Library License along with
* the ALPS Libraries; see the file LICENSE.txt. If not, the license is also
* available from http://alps.comp-phys.org/.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT 
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, 
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
* DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

/* $Id$ */

#ifndef ALPS_LATTICE_GRAPH_PROPERTIES_H
#define ALPS_LATTICE_GRAPH_PROPERTIES_H

#include <alps/lattice/propertymap.h>
#include <alps/lattice/boundary.h>
#include <boost/limits.hpp>
#include <boost/pending/property.hpp>
#include <boost/graph/adjacency_list.hpp>

#include <string>
#include <vector>

namespace alps {

struct vertex_type_t { typedef boost::vertex_property_tag kind; };
typedef vertex_type_t site_type_t;
struct coordinate_t { typedef boost::vertex_property_tag kind; };
struct parity_t { typedef boost::vertex_property_tag kind; };

struct edge_type_t { typedef boost::edge_property_tag kind; };
typedef edge_type_t bond_type_t;
struct source_offset_t { typedef boost::edge_property_tag kind; };
struct target_offset_t { typedef boost::edge_property_tag kind; };
struct boundary_crossing_t { typedef boost::edge_property_tag kind; };
struct edge_vector_t { typedef boost::edge_property_tag kind; };
typedef edge_vector_t bond_vector_t;
struct graph_name_t { typedef boost::graph_property_tag kind; };
struct dimension_t { typedef boost::graph_property_tag kind; };

using boost::vertex_index_t;
using boost::edge_index_t;

// the default graph class

typedef std::vector<double> coordinate_type;
typedef std::vector<int> offset_type;
typedef std::vector<int> distance_type;
typedef unsigned int type_type;

typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::undirectedS,
                              // vertex property
                              boost::property<coordinate_t,coordinate_type,
                                boost::property<parity_t,int8_t,
                                   boost::property<vertex_type_t,type_type> > >,
                              // edge property
                              boost::property<edge_type_t,type_type,
                                boost::property<boost::edge_index_t,unsigned int,
                                  boost::property<boundary_crossing_t,boundary_crossing,
                                    boost::property<bond_vector_t,coordinate_type> > > >,
                              // graph property
                              boost::property<dimension_t,std::size_t,
                                boost::property<graph_name_t,std::string > >
                              , boost::vecS> coordinate_graph_type;

typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::undirectedS,
                              // vertex property
                              boost::no_property,
                              // edge property
                              boost::property<boost::edge_index_t,unsigned int>,
                              // graph property
                              boost::property<dimension_t,std::size_t,
                                boost::property<graph_name_t,std::string > >
                              , boost::vecS> minimal_graph_type;

} // end namespace alps

#endif // ALPS_LATTICE_GRAPH_PROPERTIES_H
