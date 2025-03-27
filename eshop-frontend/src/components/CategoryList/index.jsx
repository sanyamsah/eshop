import React, { useState, useEffect } from 'react';
import axios from 'axios';
import Category from '../Category';
import ApiClient from '../../client/ApiClient';

const CategoryList = () => {
    const [categories, setCategories] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);
    // const getCategories = () => {
    //     // fetch('https://api.escuelajs.co/api/v1/categories')
    //     // .then(response => response.json())
    //     // .then(data => setCategories(data))
    //     // .catch(error => console.log(error));

    //     axios.get('https://api.escuelajs.co/api/v1/categories')
    //         .then(response => setCategories(response.data))
    //         .catch(error => console.log(error));
    //     // ApiClient.get("/categories")
    //     //     .then(response => setCategories(response.data))
    //     //     .catch(error => console.log(error));
    // }

    const getCategories = () => {
        ApiClient.get("/categories")
            .then(response => {
                setCategories(response.data);
                setLoading(false);
            })
            .catch(error => {
                console.error("Error fetching categories:", error);
                // setError(error.message);
                setError("Log in to view Categories.")
                setLoading(false);
            });
    }
    
    useEffect(() => {
        getCategories();
    }, []);

    if (loading) return <div>Loading categories...</div>;
    if (error) return <div><center>Message: {error}</center></div>;

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