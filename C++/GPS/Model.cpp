#include <iostream>
#include "Model.h"
/*!
 * \file Model.cpp
 *
 * \author Ryan Gouldsmih
 * \date 28th March
 *
 * This implements the model class from the model.h, this updates all the values, which are to be exported.
 */
using namespace std;
/**
* The constructor of type Mode
*/
Model::Model()
{
}
/**
* The destructor
*/
Model::~Model()
{
}
/**
* Sets the Lat for the model
* @param lat is the float value of the latitude
*/
void Model::set_lat(float lat)
{
    this->lat = lat;
}
/**
* Sets the longitude to the Model
* @param lng is the float value of the longitude
*/
void Model::set_lng(float lng)
{
    this->lng = lng;
}
/**
* Sets the latest offset value for the latitude
* @param offset the float value of the offset
*/
void Model::set_lat_offset(float offset)
{
    this->lat_offset = offset;
}
/**
* Sets the latest offset value for the longitude
* @param offset the float value of the longitude offset
*/
void Model::set_lng_offset(float offset)
{
    this->lng_offset = offset;
}
/**
* @returns the Models latitude value
*/
float Model::get_lat()
{
    return this->lat;
}
/**
* @returns the Models longitude value
*/
float Model::get_lng()
{
    return this->lng;
}
/**
* @returns the models latitude offset value
*/
float Model::get_lat_offset()
{
    return this->lat_offset;
}
/**
* @returns the models longitude offset value
*/
float Model::get_lng_offset()
{
    return this->lng_offset;
}
/**
* @returns the vector of floats from the Model class.
*/
std::vector<float> Model::get_lat_values()
{
    return this->lat_values;
}
/**
* Adds the latitude value to the vector in Model.
*/
void Model::set_lat_values(float lat)
{
    this->lat_values.push_back(lat);
}
/**
* @returns A vector of floats containing the longitude values
*/
std::vector<float> Model::get_lng_values()
{
    return this->lng_values;
}
/**
* sets the longitude value to the Vector in the Model
*/
void Model::set_lng_values(float lng)
{
    this->lng_values.push_back(lng);
}
