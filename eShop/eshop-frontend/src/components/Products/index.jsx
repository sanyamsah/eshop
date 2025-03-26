import {Link} from 'react-router-dom';

const Products = (props) => {
    const { id, title, description, price, images, category } = props.data;
    return (
        <div className="col-sm-3 mb-4"> {/* Added margin-bottom for spacing */}
            <div className="card">
                <img src={images} alt={description} className="card-img-top" /> {/* Fixed className */}
                <div className="card-body">
                    <h5 className="card-title">{title}</h5>
                    <h6>
                        <span className="badge badge-pill badge-secondary">{category?.name}</span>
                    </h6>
                    <p className="card-text">
                        {description}
                    </p>
                    <h2>
                        <span>&#36;</span>{price}
                    </h2>
                    <Link to={'/products/details/'+id} className="btn btn-primary btn-block">
                        Details
                    </Link>
                </div>
            </div>
        </div>
    );
}
export default Products;