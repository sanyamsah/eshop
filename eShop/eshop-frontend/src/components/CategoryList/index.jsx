import React, { useState, useEffect } from 'react';
import axios from 'axios';
import Category from '../Category';
import ApiClient from '../../client/ApiClient';

const CategoryList = () => {
    const [categories, setCategories] = useState([]);
    const getCategories = () => {
        // fetch('https://api.escuelajs.co/api/v1/categories')
        // .then(response => response.json())
        // .then(data => setCategories(data))
        // .catch(error => console.log(error));

        axios.get('https://api.escuelajs.co/api/v1/categories')
            .then(response => setCategories(response.data))
            .catch(error => console.log(error));
        // ApiClient.get("/categories")
        //     .then(response => setCategories(response.data))
        //     .catch(error => console.log(error));
    }
    useEffect(() => {
        getCategories();
    }, []);
    return (
        <div className='container'>
            <h2 className='text-center'>All Categories</h2>
            <div className="row">
                {
                    categories.map((category, index) => (<Category data={category} key={category.id} />))
                }
            </div>
        </div>
    );
}
export default CategoryList;