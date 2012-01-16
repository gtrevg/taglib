/***************************************************************************
    copyright           : (C) 2012 by Michael Helmling
    email               : helmling@mathematik.uni-kl.de
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,            *
 *   MA  02110-1301  USA                                                   *
 ***************************************************************************/

#ifndef PROPERTYMAP_H_
#define PROPERTYMAP_H_

#include "tmap.h"
#include "tstringlist.h"

namespace TagLib {


  //! A map for format-independent <key,valuelist> tag representations.

  /*!
   * This map implements a generic representation of textual audio metadata
   * ("tags") realized as pairs of a case-insensitive key
   * and a nonempty list of corresponding values, each value being an an arbitrary
   * Unicode String.
   * The key has the same restrictions as in the vorbis comment specification,
   * i.e. it must contain at least one character; all printable ASCII characters
   * except '=' and '~' are allowed.
   *
   */

  class PropertyMap: public Map<String,StringList>
  {
  public:

    typedef Map<String,StringList>::Iterator Iterator;
    typedef Map<String,StringList>::ConstIterator ConstIterator;

    PropertyMap();

    PropertyMap(const PropertyMap &m);

    virtual ~PropertyMap();

    /*!
     * Inserts \a values under \a key in the map.  If \a key already exists,
     * then \values will be appended to the existing StringList.
     * The returned value indicates success, i.e. whether \a key is a
     * valid key.
     */
    bool insert(const String &key, const StringList &values);

    /*!
     * Replaces any existing values for \a key with the given \a values,
     * and simply insert them if \a key did not exist before.
     * The returned value indicates success, i.e. whether \a key is a
     * valid key.
     */
    bool replace(const String &key, const StringList &values);

    /*!
     * Find the first occurrence of \a key.
     */
    Iterator find(const String &key);

    /*!
     * Find the first occurrence of \a key.
     */
    ConstIterator find(const String &key) const;

    /*!
     * Returns true if the map contains values for \a key.
     */
    bool contains(const String &key) const;

    /*!
     * Erase the \a key and its values from the map.
     */
    PropertyMap &erase(const String &key);

    /*!
     * Returns a reference to the value associated with \a key.
     *
     * \note: This has undefined behavior if the key is not valid.
     */
    const StringList &operator[](const String &key) const;

    /*!
     * Returns a reference to the value associated with \a key.
     *
     * If \a key is not present in the map, an empty list is inserted and
     * returned.
     *
     * \note: This has undefined behavior if the key is not valid.
     */
    StringList &operator[](const String &key);

    /*!
     * Converts \a proposed into another String suitable to be used as
     * a key, or returns String::null if this is not possible.
     */
    String prepareKey(const String &proposed) const;
  };

}
#endif /* PROPERTYMAP_H_ */
