/*
 * GridMapIterator.hpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Péter Fankhauser
 *   Institute: ETH Zurich, Autonomous Systems Lab
 */

#pragma once

#include "grid_map_lib/GridMap.hpp"

// Eigen
#include <Eigen/Core>

namespace grid_map_lib {

class GridMapIterator
{
public:

  /*!
   * Constructor.
   * @param gridMap the grid map to iterate upon.
   */
  GridMapIterator(const grid_map_lib::GridMap &gridMap);

  /*!
   * Copy constructor.
   * @param other the object to copy.
   */
  GridMapIterator(const GridMapIterator* other);

  /*!
   * Assignment operator.
   * @param iterator the iterator to copy data from.
   * @return a reference to *this.
   */
  GridMapIterator& operator =(const GridMapIterator& other);

  /*!
   * Compare to another iterator.
   * @return whether the current iterator points to a different address than the other one.
   */
  bool operator !=(const GridMapIterator& other) const;

  /*!
   * Dereference the iterator with const.
   * @return the value to which the iterator is pointing.
   */
  const Eigen::Array2i& operator *() const;

  /*!
   * Increase the iterator to the next element.
   * @return a reference to the updated iterator.
   */
  GridMapIterator& operator ++();

  /*!
   * Return the end iterator
   * @return the end iterator (useful when performing normal iterator processing with ++).
   */
  GridMapIterator end() const;

private:

  //! Size of the buffer.
  Eigen::Array2i bufferSize_;

  //! Start index of the circular buffer.
  Eigen::Array2i startIndex_;

  //! End index of the circular buffer.
  Eigen::Array2i endIndex_;

  //! Current index.
  Eigen::Array2i index_;
};

} /* namespace */
